// 将数据转换为包含索引的数组
const transformData = (data: any[]) => [...data.map((v) => v.time), ...data.map((v) => v.troops)]

export async function probabilityPIMC(kr: number, kb: number, data: any[], days: number) {
  // 触发计算
  return window.electron.ipcRenderer.invoke('probabilityPIMC', {
    kr,
    kb,
    data: transformData(data),
    t_known: days
  })
}

export async function calculator(params) {
  // 触发计算
  return await window.electron.ipcRenderer.invoke('calculator', {
    ...params,
    compare_data: transformData(params.compare_data)
  })
}

export function calculateQtfisher(c1, c2, c3, t, qr_0) {
  return Math.round(qr_0 - c1 * t - c2 * Math.sin((c1 / c2) * t + c3) + c2 * Math.sin(c3))
}

export function calculateQtsquare(kr, kb, t, qr_0, qb_0) {
  return Math.round(
    qr_0 * Math.cosh(Math.sqrt(kr * kb) * t) -
      Math.sqrt(kb / kr) * qb_0 * Math.sinh(Math.sqrt(kr * kb) * t)
  )
}

const rate = (n) => Number(n).toFixed(6)

export const calculatorOutput = async (params, result, nexttime: number = 3) => {
  const { time_known: t_known, inital_troops } = params
  const qb_0 = inital_troops

  const { t_data, kr, kb, c1, c2, c3, qr_0 } = result
  const qtfisher_data = [...result.qtfisher_data]
  const qtsquare_data = [...result.qtsquare_data]
  const compare_data = [...result.compare_data]

  const data: any[] = []
  const qtfisher: any[] = []
  const qtsquare: any[] = []

  compare_data.forEach((v, idx) => {
    qtfisher[idx] = { time: v.time, troops: qtfisher_data[idx] }
    qtsquare[idx] = { time: v.time, troops: qtsquare_data[idx] }
    data[idx] = { time: v.time, troops: v.troops }
  })

  // 初始化结果数组
  const results: any[] = []

  const ti_known = t_data.findIndex((v) => t_known === v)

  for (let i = 1; i <= nexttime; i++) {
    const idx = ti_known + i
    const day = t_data[idx] || t_data[t_data.length - 1] + idx - t_data.length + 1

    const output: Record<string, any> = {
      t: day
    }
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

    let qtfisher_i
    let qtsquare_i

    console.log(idx, t_data.length)
    if (idx < t_data.length) {
      qtfisher_i = qtfisher_data[idx]
      qtsquare_i = qtsquare_data[idx]
      const inital_troops_i = compare_data[idx].troops
      output['本项目模型与战役数据的差'] = qtfisher_i - inital_troops_i
      output['兰彻斯特模型数据与战役数据的差'] = qtsquare_i - inital_troops_i
      output['实际兵力数'] = inital_troops_i
      data[idx] = { time: day, troops: inital_troops_i }
    } else {
      qtfisher_i = calculateQtfisher(c1, c2, c3, day, qr_0)
      qtsquare_i = calculateQtsquare(kr, kb, day, qr_0, qb_0)

      qtfisher_data[idx] = qtfisher_i
      qtsquare_data[idx] = qtsquare_i
    }
    qtfisher[idx] = { time: day, troops: qtfisher_i }
    qtsquare[idx] = { time: day, troops: qtsquare_i }

    const probability = rate(await probabilityPIMC(kr, kb, data, day))
    console.log('probability', day, probability)

    output['本项目模型预测的兵力数'] = qtfisher_i
    output['兰彻斯特模型预测的兵力数'] = qtsquare_i
    output['预测兵力数的概率'] = probability
    output['本项目模型的损耗速率(人/天)'] = rate(basicLossRate)
    output['本项目模型的日损耗率'] = rate(dailyLossRate)
    output['兰彻斯特模型的损耗速率（人/天）'] = rate(lancasterLossRate)
    output['兰彻斯特模型的日损耗率'] = rate(lancasterDailyLossRate)

    results.push(output)
  }

  console.log(qtfisher)

  return {
    outputs: results,
    norm: result.norm,
    norm2: result.norm2,
    qtfisher,
    qtsquare,
    data
  }
}
