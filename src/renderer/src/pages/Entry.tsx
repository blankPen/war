import { Background } from '@/components/Background'
// import electronLogo from '@/assets/electron.svg'
import { useAppStore } from '@/store'
import { Flex, Button } from 'antd'

export default function Entry(): JSX.Element {
  const store = useAppStore()

  return (
    <>
      <Background />
      <Flex vertical align="center" justify="center" className="h-lvh relative">
        {/* <img alt="logo" className="logo" src={electronLogo} /> */}
        <h1 className="text-6xl text-white">军事冲突演化模拟平台</h1>
        <Flex gap="middle" className="mt-10">
          <Button size="large" onClick={() => store.go('Calculator')} type="primary">
            开始演算
          </Button>
          {/* <Button size="large" onClick={() => store.go('History')}>
            查看历史
          </Button> */}
        </Flex>
      </Flex>
    </>
  )
}
