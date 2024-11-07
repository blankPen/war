// 将数据转换为包含索引的数组
const transformData = (data: any[]) => [...data.map((_, i) => i), ...data]

async function probabilityPIMC(kr: number, kb: number, data: any[], days: number) {
  // 触发计算
  return window.electron.ipcRenderer.invoke('probabilityPIMC', {
    kr,
    kb,
    data: transformData(data),
    t_known: days
  })
}

async function calculator(params) {
  // 触发计算
  return await window.electron.ipcRenderer.invoke('calculator', {
    ...params,
    compare_data: transformData(params.compare_data)
  })
}

export { probabilityPIMC, calculator }
