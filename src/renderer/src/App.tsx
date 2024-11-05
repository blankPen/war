import { ConfigProvider, theme } from 'antd'
// import { Background } from '@/components/Background'
import Entry from '@/pages/Entry'
import Calculator from '@/pages/Calculator'
import { useAppStore } from '@/store'

import './app.css'

const Pages = {
  Entry,
  Calculator
}
function App(): JSX.Element {
  const store = useAppStore()
  const Page = Pages[store.page]

  return (
    <ConfigProvider
      theme={{
        // algorithm: theme.darkAlgorithm,
        token: {
          // // Seed Token，影响范围大
          // colorPrimary: '#00b96b',
          // borderRadius: 2,

          // // 派生变量，影响范围小
          // colorBgContainer: '#f6ffed'
        }
      }}
    >
      {/* <Background /> */}
      {Page && <Page />}
    </ConfigProvider>
  )
}

export default App
