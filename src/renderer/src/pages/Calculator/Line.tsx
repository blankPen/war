import { Line, LineConfig } from '@ant-design/plots'
import { useEffect, useRef, useState, memo } from 'react'

const ChatLine = memo(function Line2({
  qtfisher,
  qtsquare,
  data
}: {
  data: any[]
  qtfisher: any[]
  qtsquare: any[]
}) {
  // 添加容器引用和尺寸状态
  const containerRef = useRef<HTMLDivElement>(null)
  const [dimensions, setDimensions] = useState({})
  const [renderKey, setRenderKey] = useState(Date.now())
  // 监听容器尺寸变化
  useEffect(() => {
    const updateDimensions = () => {
      if (containerRef.current) {
        setDimensions({
          width: containerRef.current.clientWidth,
          height: containerRef.current.clientHeight
        })
        setRenderKey(Date.now())
      }
    }

    // 初始化尺寸
    // updateDimensions()

    // 创建 ResizeObserver 监听尺寸变化
    const observer = new ResizeObserver(updateDimensions)
    if (containerRef.current) {
      observer.observe(containerRef.current)
    }

    return () => observer.disconnect()
  }, [])

  // useEffect(() => {

  // }, [dimensions])
  const config: LineConfig = {
    // title: '军事冲突演化模拟平台',
    data: [
      ...data.map((v) => ({ ...v, type: '历史战役' })),
      ...qtfisher.map((v) => ({ ...v, type: '本模型' })),
      ...qtsquare.map((v) => ({ ...v, type: '兰切斯特模型' }))
      // ...qtfisher.map((v, i) => ({ time: i, value: v, color: 'c3', type: '本模型' })),
      // ...qtsquare.map((v, i) => ({ time: i, value: v, color: 'c4', type: '兰切斯特模型' }))
    ],
    // color: ({ type, ...res }) => {
    //   console.log(type, res)
    //   if (type === '历史战役') {
    //     return 'red'
    //   }
    //   return 'blue'
    // },
    line: {
      width: 2
    },
    point: {
      shapeField: 'square',
      sizeField: 2,
      tooltip: false
    },
    xField: 'time',
    yField: 'troops',
    // seriesField: 'type',
    colorField: 'type',
    xAxis: {
      label: {
        formatter: (v) => `${v}天`
      }
    },
    yAxis: {
      label: {
        formatter: (v) => `${(v / 1000).toFixed(2)}k`
      }
    },
    // legend: {
    //   position: 'right-top'
    // },
    smooth: true,
    animate: { enter: { type: 'growInX' } },
    ...dimensions,
    autoFit: true // 启用自适应
  }

  return (
    <div ref={containerRef} style={{ width: '100%', height: '100%', display: 'flex' }}>
      <Line key={renderKey} {...config} />
    </div>
  )
})

export default ChatLine
