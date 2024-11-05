import { Button } from '@headlessui/react'
// import { Background } from '@/components/Background'
import electronLogo from '@/assets/electron.svg'
import { useAppStore } from '@/store'

export default function Entry(): JSX.Element {
  const store = useAppStore()
  const actions = [
    { label: '开始演算', action: (): void => store.go('Calculator') },
    { label: '查看历史', action: (): void => store.go('History') }
  ]

  return (
    <>
      <img alt="logo" className="logo" src={electronLogo} />
      <div className="text-white text">
        <span>战阵演算系统</span>
      </div>
      <div className="actions">
        {actions.map((v) => (
          <Button
            key={v.label}
            className="w-40 h-12 items-center gap-2 rounded-sm bg-gray-700/50 py-1.5 px-3 text-sm/6 font-semibold text-white shadow-inner focus:outline-none data-[hover]:bg-gray-600 data-[open]:bg-gray-700 data-[focus]:outline-1 data-[focus]:outline-white mr-2"
            onClick={v.action}
          >
            {v.label}
          </Button>
        ))}
      </div>
    </>
  )
}
