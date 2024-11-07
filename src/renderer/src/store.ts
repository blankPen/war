import { create } from 'zustand'
import { calculator } from './lib/algorithm'

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
  step: 0,
  params: {
    inital_troops: 10000,
    time_known: 3,
    // compare_data: ``,
    compare_data: `513056, 511467, 509084, 506999, 504824, 503435, 502261, 500356, 498808, 497200, 495673, 493353, 491977, 490700, 489695, 488653, 487494, 486490, 485658, 483827, 481568, 479929, 478701, 476833, 475557, 474178, 472535, 471254, 470171, 468490, 466893, 464795`
  },
  result: null as any,
  set,
  setSetp: (step: number) => set({ step }),
  next: () => set(({ step }) => ({ step: Math.min(step + 1, 3) })),
  prev: () => set(({ step }) => ({ step: Math.max(step - 1, 0) })),
  reset: () => set({ step: 0 }),
  async submitCalculator(params) {
    const compareData = params.compare_data
      .split(',')
      .map((v) => v.trim())
      .filter((v) => v.length)
      .map((v) => Number(v))
    // 保存数据，跳转到下一步
    set({ params, step: 1 })
    const result = await calculator({
      ...params,
      compare_data: compareData
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
