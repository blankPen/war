import type { UploadProps } from 'antd'
import { Flex, Form, Input, Button, InputNumber, Upload, Table, Space, message } from 'antd'
import { UploadOutlined } from '@ant-design/icons'
import { useAppStore, useCalculatorStore } from '@/store'
import { Box } from '@/components/Box'
import { useEffect, useState } from 'react'
import * as XLSX from 'xlsx'

interface IData {
  dataIndex?: number
  time: number
  troops: number
}

const InputData = ({
  value,
  onChange
}: {
  value?: IData[]
  onChange?: (value: IData[]) => void
}) => {
  const uplpadProps: UploadProps = {
    name: 'file',
    accept: '.xlsx',
    beforeUpload(file: File) {
      return new Promise((resolve) => {
        const reader = new FileReader()
        reader.readAsArrayBuffer(file)
        reader.onload = (e) => {
          const data = e.target?.result as ArrayBuffer
          const workbook = XLSX.read(data, { type: 'array' })
          const firstSheet = workbook.Sheets[workbook.SheetNames[0]]
          const jsonData = XLSX.utils.sheet_to_json(firstSheet)
          const a1 = firstSheet.A1.v
          const b1 = firstSheet.B1.v
          // 转换数据格式
          const formattedData = jsonData.map((item: any) => ({
            dataIndex: Math.random(),
            time: item[a1],
            troops: item[b1]
          }))

          onChange?.(formattedData)
          message.success('数据导入成功')
          resolve(Upload.LIST_IGNORE)
        }
      })
    },
    maxCount: 1,
    multiple: false
  }

  const [data, setData] = useState<IData[]>([])

  useEffect(() => {
    setData(value?.length ? value : [{ dataIndex: 1, time: 0, troops: 10000 }])
  }, [value])

  const onChangeValue = (key: string, v: string, i: number) => {
    onChange?.([
      ...data.slice(0, i),
      {
        ...data[i],
        [key]: v
      },
      ...data.slice(i + 1)
    ])
  }

  return (
    <>
      <Flex justify="start" className="mb-2">
        <div className="flex items-center">
          <Upload {...uplpadProps} className="inline mr-2">
            <Button icon={<UploadOutlined />}>上传数据</Button>
          </Upload>
        </div>
      </Flex>
      <Table
        bordered
        size="small"
        sticky
        scroll={{ y: 200 }}
        pagination={false}
        rowKey="dataIndex"
        columns={[
          {
            title: '天数',
            dataIndex: 'time',
            render: (v, _, i) => (
              <InputNumber
                precision={0}
                min={0}
                value={v}
                onChange={(e) => onChangeValue('time', e.target.value, i)}
              />
            )
          },
          {
            title: '兵力',
            dataIndex: 'troops',
            render: (v, _, i) => (
              <InputNumber
                precision={0}
                min={0}
                value={v}
                onChange={(e) => onChangeValue('troops', e.target.value, i)}
              />
            )
          },
          {
            title: '操作',
            render: (_, record, i) => (
              <Space size="small">
                <Button
                  size="small"
                  type="link"
                  onClick={() =>
                    setData([
                      ...data.slice(0, i + 1),
                      { dataIndex: Date.now(), time: record.time + 1, troops: record.troops || 0 },
                      ...data.slice(i + 1)
                    ])
                  }
                >
                  添加
                </Button>
                <Button
                  size="small"
                  type="link"
                  onClick={() => {
                    if (data.length > 1) setData(data.filter((v) => v.time !== record.time))
                    else message.error('至少保留一行数据')
                  }}
                >
                  删除
                </Button>
              </Space>
            )
          }
        ]}
        dataSource={data}
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
            rules={[{ required: true, message: '请输入或上传对照数据' }]}
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
              min={1}
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
              min={1}
              precision={0}
            />
          </Form.Item>
          {/* <Form.Item name="mode" label="对比模型" required>
 <Select placeholder="请输入" />
 </Form.Item> */}
          <Flex align="center" justify="center">
            <Button size="large" type="default" className="w-20 mr-2" onClick={() => go('Entry')}>
              返回
            </Button>
            <Button size="large" type="primary" className="w-20 mr-2" htmlType="submit">
              下一步
            </Button>
          </Flex>
        </Form>
      </Flex>
    </Box>
  )
}
