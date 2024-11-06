import { create } from 'zustand'

type Page = 'Entry' | 'Calculator' | 'History'

export interface IGlobalState {
  page: Page
  go: (page: Page) => void
}

export const useAppStore = create<IGlobalState>((set) => ({
  page: 'Calculator',
  go: (page) => set({ page })
}))

const createCalculatorFn = (set) => ({
  step: 2,
  params: {
    inital_troops: 10000,
    time_known: 3,
    compare_data: ``
  },
  result: null as any,
  set,
  setSetp: (step: number) => set({ step }),
  next: () => set(({ step }) => ({ step: Math.min(step + 1, 3) })),
  prev: () => set(({ step }) => ({ step: Math.max(step - 1, 0) })),
  reset: () => set({ step: 0 }),
  computedCompareData: () => {},
  async submitCalculator(params) {
    const compareData = params.compare_data
      .split(',')
      .map((v) => v.trim())
      .filter((v) => v.length)
      .map((v) => Number(v))
    // 保存数据，跳转到下一步
    set({ params, step: 1 })
    // 触发计算
    const result = await window.electron.ipcRenderer.invoke('calculator', {
      ...params,
      compare_data: [...compareData.map((_, i) => i), ...compareData]
    })

    result.compare_data = compareData
    // 计算结束后，跳转到下一步
    set({ step: 2, result })
  }
})
export const useCalculatorStore = create<ReturnType<typeof createCalculatorFn>>(createCalculatorFn)

// function sleep(num: number) {
//   return new Promise((resolve) => {
//     setTimeout(resolve, num)
//   })
// }
