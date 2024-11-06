import { Flex, Form, Input, Button, InputNumber, Upload, UploadProps } from 'antd'
import { UploadOutlined } from '@ant-design/icons'
import { useAppStore, useCalculatorStore } from '@/store'
import { Box } from '@/components/Box'

const InputData = ({ value, onChange }: { value?: string; onChange?: (value: string) => void }) => {
  const uplpadProps: UploadProps = {
    name: 'file',
    accept: '.txt',
    beforeUpload(file: File) {
      return new Promise((resolve) => {
        const reader = new FileReader()
        reader.readAsText(file)
        reader.onload = (e) => {
          const text = String(e.target?.result)
          onChange?.(text)
          resolve(Upload.LIST_IGNORE)
        }
      })
    },
    maxCount: 1,
    multiple: false
  }
  return (
    <>
      <div className="flex items-center mb-2">
        <Upload {...uplpadProps} className="inline">
          <Button icon={<UploadOutlined />}>上传数据</Button>
        </Upload>
        <span className="ml-2">请上传 .txt 格式文件，数据内容用逗号分隔</span>
      </div>
      <Input.TextArea
        style={{ height: 200 }}
        value={value}
        onChange={(e) => onChange?.(e.target.value)}
        placeholder="请输入对照数据，格式参考: 5000, 4900, 4800, ..."
      />
    </>
  )
}

export const Step1 = () => {
  const { go } = useAppStore()
  const { submitCalculator, params } = useCalculatorStore()
  const [form] = Form.useForm()
  const onNext = async () => {
    const values = await form.validateFields()
    submitCalculator(values)
  }

  return (
    <Box>
      <Flex className="w-full" justify="center">
        <Form initialValues={params} form={form} onFinish={onNext} className="w-full">
          <Form.Item
            name="compare_data"
            label="历史战役数据"
            required
            rules={[
              { required: true, message: '请输入或上传对照数据' },
              {
                async validator(_, value: string) {
                  if (value) {
                    const values = value
                      .split(',')
                      .map((v) => v.trim())
                      .filter((v) => v.length)
                    if (values.find((v) => !/^\d+$/.test(v))) throw new Error('请输入正确的数据')
                  }
                  return Promise.resolve()
                }
              }
            ]}
          >
            <InputData />
          </Form.Item>
          <Form.Item
            name="inital_troops"
            label="初始兵力"
            required
            rules={[{ required: true, message: '请输入初始兵力' }]}
          >
            <InputNumber
              className="w-full"
              type="number"
              placeholder="请输入"
              min={0}
              precision={0}
            />
          </Form.Item>
          <Form.Item
            name="time_known"
            label="已知天数"
            required
            rules={[{ required: true, message: '请输入已知天数' }]}
          >
            <InputNumber
              className="w-full"
              type="number"
              placeholder="请输入"
              min={0}
              max={31}
              precision={0}
            />
          </Form.Item>
          {/* <Form.Item name="mode" label="对比模型" required>
          <Select placeholder="请输入" />
        </Form.Item> */}
          <Flex align="center" justify="center">
            <Button type="default" className="w-20 mr-2" onClick={() => go('Entry')}>
              返回
            </Button>
            <Button type="primary" className="w-20 mr-2" htmlType="submit">
              下一步
            </Button>
          </Flex>
        </Form>
      </Flex>
    </Box>
  )
}
