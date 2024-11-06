// import { Background } from '@/components/Background'
import electronLogo from '@/assets/electron.svg'
import { useAppStore } from '@/store'
import { Flex, Button } from 'antd'

export default function Entry(): JSX.Element {
  const store = useAppStore()

  return (
    <Flex vertical align="center" justify="center" className="h-lvh">
      <img alt="logo" className="logo" src={electronLogo} />
      <div className="text-white text">
        <span>战阵演算系统</span>
      </div>
      <Flex gap="middle">
        <Button size="large" onClick={() => store.go('Calculator')} type="primary">
          开始演算
        </Button>
        <Button size="large" onClick={() => store.go('History')}>
          查看历史
        </Button>
      </Flex>
    </Flex>
  )
}
