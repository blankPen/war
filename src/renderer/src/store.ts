import { create } from 'zustand'
import { calculator } from './lib/algorithm'
import { message } from 'antd'

type Page = 'Entry' | 'Calculator' | 'History'

export interface IGlobalState {
  page: Page
  go: (page: Page) => void
}

export const useAppStore = create<IGlobalState>((set) => ({
  page: 'Entry',
  go: (page) => set({ page })
}))

const createCalculatorFn = (set) => ({
  step: 0,
  params: {
    inital_troops: 100,
    time_known: 3,
    compare_data: []
    // compare_data: `66469,65509,64507,63045,62586,61710,60791,59789,59624,59374,59125,58583,57748,56955,56497,55871,55245,54829,54287,53786,53453,53246,53246,52914,52790,52708,52584,52544,52504,52504,52465`
  },
  result: null as any,
  nextTime: 3,
  set,
  setSetp: (step: number) => set({ step }),
  next: () => set(({ step }) => ({ step: Math.min(step + 1, 3) })),
  prev: () => set(({ step }) => ({ step: Math.max(step - 1, 0) })),
  reset: () => set({ step: 0 }),
  async submitCalculator(params) {
    // const compareData = params.compare_data
    if (params.compare_data.every((v) => v.time !== params.time_known)) {
      message.error('输入错误：输入数据中未包含已知时间数据')
      return
    }

    // 保存数据，跳转到下一步
    set({ params, step: 1 })
    const result = await calculator(params)

    console.log('==>>result', result)
    if (result.error_code) {
      const errorMap = {
        1: '输入错误：兵力数应为非负数',
        2: '输入错误：时间应为非负数',
        3: '输入错误：兵力数应为非负数',
        4: '输入错误：输入数据中未包含已知时间数据'
      }
      message.error(errorMap[result.error_code] || '未知错误')
      set({ params, step: 0 })
      return
    }
    result.compare_data = params.compare_data
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
