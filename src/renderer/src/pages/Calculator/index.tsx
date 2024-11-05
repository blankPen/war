import { Flex, Row, Col, Card, Divider, Form, Input, Button, Empty, Spin, Steps } from 'antd'
import { LoadingOutlined } from '@ant-design/icons';
import './index.css'
import ChatLine from './Line'
import { useAppStore } from '@/store'
// const { Header, Footer, Sider, Content } = Layout

export default function Deduction(): JSX.Element {
  const { go } = useAppStore()
  const [form] = Form.useForm()

  const onFinish = (values: unknown) => {
    console.log(form, values)
  }
  return (
    <>
      <Flex gap="small" vertical className="w-full h-full p-10">
        <Steps
          current={1}
          items={[
            {
              title: '初始化',
              description: '设置对照战役兵力数据'
            },
            {
              title: '执行演算',
              icon: <LoadingOutlined />,
              description: '根据模型参数执行演算'
            },
            {
              title: '查看结果'
            }
          ]}
        />
        <Card>
          <Form form={form} layout="inline" onFinish={onFinish}>
            <Form.Item name="initial" label="初始兵力">
              <Input type="number" placeholder="请输入" />
            </Form.Item>
            <Form.Item name="time_known" label="已知天数">
              <Input type="number" placeholder="请输入" />
            </Form.Item>
            <Form.Item name="mode" label="对比模型">
              <Input placeholder="请输入" />
            </Form.Item>
            <Form.Item>
              <Button type="primary" className="mr-2" htmlType="submit">
                执行演算
              </Button>
              <Button type="default" onClick={() => go('Entry')}>
                返回
              </Button>
            </Form.Item>
          </Form>
        </Card>
        <Flex>
          <Card className="w-full h-full">
            <Spin spinning>
              <Empty className="w-full h-100" description="暂无数据" />
              <Flex className="w-full h-full">
                <div style={{ width: 240, height: '100%', overflow: 'auto' }}>
                  {[...new Array(31)].map((v, i) => (
                    <Button key={i} type="text" block>
                      第{i}天
                    </Button>
                  ))}
                </div>
                <Divider type="vertical" className="h-auto" />
                <ChatLine />
              </Flex>
            </Spin>
          </Card>
        </Flex>
      </Flex>
      {/* <div className="flex flex-row rounded bg-slate-700 p-4 w-full space-x-2">
        <label className="input input-bordered flex items-center gap-2">
          初始兵力
          <input type="text" className="grow" placeholder="number" />
        </label>
        <select className="select select-bordered w-full max-w-xs">
          <option disabled selected>
            选择对照模型
          </option>
          <option>Han Solo</option>
          <option>Greedo</option>
        </select>
        <label className="input input-bordered flex items-center gap-2">
          Name
          <input type="text" className="grow" placeholder="Daisy" />
        </label>

        <button className="btn btn-primary">开始计算</button>
      </div>
      <div className="flex grow overflow-hidden space-x-4 w-full">
        <div className="flex flex-col rounded bg-slate-700 p-2 overflow-auto h-full w-1/4">
          {[...new Array(31)].map((v, i) => (
            <button className="btn btn-sm mb-2" key={i}>
              第{i}天
            </button>
          ))}
        </div>
        <div className="flex flex-col rounded bg-slate-700 p-2 overflow-auto  w-3/4">
          <ChatLine />
        </div>
      </div> */}
    </>
  )
}
