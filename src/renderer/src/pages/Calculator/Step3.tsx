/* eslint-disable @typescript-eslint/no-explicit-any */
import { Flex, Button, Divider, Input, InputNumber } from 'antd'
import { useCalculatorStore, useAppStore } from '@/store'
import { Box } from '@/components/Box'
import ChatLine from './Line'
import { useEffect, useState } from 'react'
import { calculatorOutput } from '@/lib/algorithm'

export const Step3 = () => {
  const { go } = useAppStore()
  const { reset, params, result, nextTime, set } = useCalculatorStore()
  // const { qtfisher_data, qtsquare_data, data_data, norm, norm2 } = result || {}
  const [results, setResults] = useState<any>({})

  const { outputs, norm, norm2, qtfisher, qtsquare, data } = results || {}
  useEffect(() => {
    const getResults = async () => {
      if (result) {
        const results = await calculatorOutput(params, result, nextTime)
        setResults(results)
      }
    }
    getResults()
  }, [result, nextTime])

  return (
    <Flex vertical gap="middle" className="overflow-auto">
      <Flex className="w-full overflow-hidden" justify="center" gap="middle">
        {/* 日志展示 */}
        <Box className="p-4 w-2/5 overflow-auto">
          <p className="mb-2">
            <span>当前预测出天数：</span>
            <InputNumber
              className="inline-block w-20"
              value={nextTime}
              min={1}
              max={100}
              onChange={(v) => set({ nextTime: v })}
            />
          </p>
          {norm !== undefined && <p className="mb-2">本项目模型的二范数：{norm.toFixed(4)}</p>}
          {norm2 !== undefined && <p className="mb-2">兰彻斯特模型的二范数：{norm2.toFixed(4)}</p>}
          <Divider />
          {outputs?.map(({ t, ...obj }, i) => {
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
          {qtfisher && qtsquare && data && (
            <ChatLine qtfisher={qtfisher} qtsquare={qtsquare} data={data} />
          )}
        </Box>
      </Flex>
      <Flex justify="center" gap="middle">
        <Button
          size="large"
          onClick={() => {
            reset()
            go('Entry')
          }}
        >
          返回首页
        </Button>
        <Button size="large" type="primary" onClick={reset}>
          重新计算
        </Button>
      </Flex>
    </Flex>
  )
}
