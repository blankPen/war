/* eslint-disable @typescript-eslint/no-explicit-any */
import { Flex, Button, Divider } from 'antd'
import { useCalculatorStore, useAppStore } from '@/store'
import { Box } from '@/components/Box'
import ChatLine from './Line'

const calculatorResult = (params, result) => {
  const { time_known: ti_known, inital_troops } = params
  const qb_0 = inital_troops

  const {
    t_data,
    kr,
    kb,
    c1,
    c2,
    c3,
    qr_0,
    qtfisher_data: qtfisher,
    qtsquare_data: qtsquare,
    compare_data: data
  } = result
  console.log(result)
  // const num_grid_points_r = 5000
  // const data = compare_data
  //   .split(',')
  //   .map((v) => Number(v.trim()))
  //   .filter((v) => v)
  const nexttime = 3
  // 初始化结果数组
  const results: any[] = []

  for (let i = 1; i <= nexttime; i++) {
    const day = t_data[ti_known + i - 1]
    const qtfisher_i = qtfisher[ti_known + i - 1]
    const qtsquare_i = qtsquare[ti_known + i - 1]
    const inital_troops_i = data[ti_known + i - 1]
    const basicLossRate = -(-c1 - c1 * Math.cos((c1 / c2) * day + c3))
    const dailyLossRate =
      basicLossRate /
      Math.round(qr_0 - c1 * day - c2 * Math.sin((c1 / c2) * day + c3) + c2 * Math.sin(c3))
    const lancasterLossRate = -(
      -kr * qb_0 * Math.cosh(Math.sqrt(kr * kb) * day) +
      Math.sqrt(kr * kb) * qr_0 * Math.sinh(Math.sqrt(kr * kb) * day)
    )
    const lancasterDailyLossRate =
      lancasterLossRate /
      Math.round(
        qr_0 * Math.cosh(Math.sqrt(kr * kb) * day) -
          Math.sqrt(kb / kr) * qb_0 * Math.sinh(Math.sqrt(kr * kb) * day)
      )

    // const probability = probability_PIMC(kr, kb, data, day, num_grid_points_r)

    // results.push([
    //   day,

    //   qtfisher_i - inital_troops_i,
    //   qtsquare_i - inital_troops_i,
    //   inital_troops_i,
    //   qtfisher_i,
    //   qtsquare_i,
    //   '-', // probability,
    //   basicLossRate,
    //   dailyLossRate,
    //   lancasterLossRate,
    //   lancasterDailyLossRate
    // ])

    const rate = (n) => Number(n).toFixed(4)
    results.push({
      t: day + 1,
      本项目模型与战役数据的差: qtfisher_i - inital_troops_i,
      兰彻斯特模型数据与战役数据的差: qtsquare_i - inital_troops_i,
      实际兵力数: inital_troops_i,
      本项目模型预测的兵力数: qtfisher_i,
      兰彻斯特模型预测的兵力数: qtsquare_i,
      预测兵力数的概率: '-', // num(qtsquare_i),
      '本项目模型的损耗速率(人/天)': rate(basicLossRate),
      本项目模型的日损耗率: rate(dailyLossRate),
      '兰彻斯特模型的损耗速率（人/天）': rate(lancasterLossRate),
      兰彻斯特模型的日损耗率: rate(lancasterDailyLossRate)
    })
  }

  return results
}

export const Step3 = () => {
  const { go } = useAppStore()
  const { reset, params, result } = useCalculatorStore()

  const { qtfisher_data, qtsquare_data, compare_data } = result || {}

  const results = result ? calculatorResult(params, result) : []
  console.log(results)
  return (
    <Flex vertical gap="middle" className="overflow-auto">
      <Flex className="w-full overflow-hidden" justify="center" gap="middle">
        {/* 日志展示 */}
        <Box className="p-4 w-2/5 overflow-auto">
          {results.map(({ t, ...obj }, i) => {
            return (
              <div key={i}>
                {i !== 0 && <Divider />}
                {Object.keys(obj).map((k, i2) => (
                  <p className="mb-2" key={i2}>
                    第 {t} 天-{k}：{obj[k]}
                  </p>
                ))}
              </div>
            )
          })}
        </Box>
        {/* Line */}
        <Box className="p-4 w-3/5">
          <ChatLine qtfisher={qtfisher_data} qtsquare={qtsquare_data} data={compare_data} />
        </Box>
      </Flex>
      <Flex justify="center" gap="middle">
        <Button
          onClick={() => {
            reset()
            go('Entry')
          }}
        >
          返回首页
        </Button>
        <Button type="primary" onClick={reset}>
          重新计算
        </Button>
      </Flex>
    </Flex>
  )
}
