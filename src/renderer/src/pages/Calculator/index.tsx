import { Flex, Steps } from 'antd'
import { LoadingOutlined } from '@ant-design/icons'
import './index.css'
import { useCalculatorStore } from '@/store'
import { Step1 } from './Step1'
import { Step2 } from './Step2'
import { Step3 } from './Step3'
import { useMemo } from 'react'

export default function Deduction(): JSX.Element {
  const { step } = useCalculatorStore()

  const stepItems = useMemo(() => {
    return [
      {
        title: '初始化',
        description: '设置对照战役兵力数据',
        renderContent: () => <Step1 />
      },
      {
        title: '执行演算',
        icon: step == 1 ? <LoadingOutlined /> : null,
        description: '根据模型参数执行演算',
        renderContent: () => <Step2 />
      },
      {
        title: '查看结果',
        renderContent: () => <Step3 />
      }
    ]
  }, [step])

  return (
    <>
      <Flex vertical className="w-full h-full p-10">
        <Steps
          className="mb-10"
          current={step}
          items={stepItems.map(({ title, description, icon }) => ({ title, description, icon }))}
        />
        {stepItems[step]?.renderContent()}
      </Flex>
    </>
  )
}
