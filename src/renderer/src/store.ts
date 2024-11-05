import { create } from 'zustand'

type Page = 'Entry' | 'Calculator' | 'History'

export interface IGlobalState {
  page: Page
  go: (page: Page) => void
}

export const useAppStore = create<IGlobalState>((set) => ({
  page: 'Calculator',
  // page: 'Entry',
  go: (page) => set({ page }),

  // state for calculator
  calculator: {
    params: {
      initialValue: 0,
      time_known: 0,
      data: [],
    }
  }

  // increasePopulation: () => set((state) => ({ bears: state.bears + 1 })),
  // removeAllBears: () => set({ bears: 0 }),
}))

export const useCalculatorStore = create((set) => ({
  params: {
    initialValue: 0,
    time_known: 0,
    data: [],
  },
  set
}))
