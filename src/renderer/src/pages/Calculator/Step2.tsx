import { Flex, Form, Button, Progress, Input } from 'antd'
import { useCalculatorStore } from '@/store'
import { useEffect, useRef, useState } from 'react'
import { Box } from '@/components/Box'

const MockProgress = () => {
  const timer = useRef<NodeJS.Timeout>()
  const [percent, setPercent] = useState(0)

  useEffect(() => {
    timer.current = setInterval(() => {
      setPercent((percent) => percent + (100 - percent) * 0.1)
    }, 200)
    return () => clearInterval(timer.current)
  }, [])

  return (
    <>
      <Progress percent={percent} status="active" format={(percent) => `${percent?.toFixed(2)}%`} />
    </>
  )
}

export const Step2 = () => {
  const {
    // prev,
    // next,
    params
  } = useCalculatorStore()
  return (
    <Box>
      <Flex className="w-full" justify="center">
        <Form
          // initialValues={initialValues} form={form} onFinish={onNext}
          className="w-full"
        >
          <Form.Item label="对照数据">
            <Input.TextArea disabled readOnly value={params.compare_data} style={{ height: 200 }} />
          </Form.Item>
          <Form.Item label="初始兵力">{params.inital_troops}</Form.Item>
          <Form.Item label="已知天数">{params.time_known}</Form.Item>

          <MockProgress />

          {/* <Flex align="center" justify="center" className="mt-10">
            <Button type="default" className="w-30 mr-2" onClick={prev}>
              取消计算
            </Button>
            <Button type="primary" className="w-20 mr-2" onClick={next}>
              下一步
            </Button>
          </Flex> */}
        </Form>
      </Flex>
    </Box>
  )
}
