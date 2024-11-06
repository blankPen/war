import { Line, LineConfig } from '@ant-design/plots'

const ChatLine = ({
  qtfisher,
  qtsquare,
  data
}: {
  data: number[]
  qtfisher: number[]
  qtsquare: number[]
}) => {
  data = [
    513056, 511467, 509084, 506999, 504824, 503435, 502261, 500356, 498808, 497200, 495673, 493353,
    491977, 490700, 489695, 488653, 487494, 486490, 485658, 483827, 481568, 479929, 478701, 476833,
    475557, 474178, 472535, 471254, 470171, 468490, 466893, 464795
  ]
  qtsquare = [
    513056, 511015, 509045, 507145, 505316, 503557, 501868, 500249, 498699, 497218, 495806, 494463,
    493189, 491983, 490845, 489776, 488774, 487840, 486974, 486176, 485445, 484781, 484185, 483656,
    483194, 482799, 482471, 482210, 482016, 481889, 481829, 481835
  ]
  qtfisher = [
    513056, 511062, 509106, 507197, 505344, 503557, 501842, 500208, 498661, 497206, 495848, 494590,
    493434, 492383, 491436, 490592, 489851, 489208, 488660, 488201, 487827, 487530, 487302, 487136,
    487023, 486952, 486914, 486899, 486897, 486895, 486885, 486856
  ]
  const config: LineConfig = {
    // title: '军事冲突演化模拟平台',
    data: [
      ...data.map((v, i) => ({
        time: i,
        value: v,
        type: '历史战役',
        color: i > 20 ? 'c2' : 'c1'
      })),
      ...qtfisher.map((v, i) => ({ time: i, value: v, color: 'c3', type: '本模型' })),
      ...qtsquare.map((v, i) => ({ time: i, value: v, color: 'c4', type: '兰切斯特模型' }))
    ],
    color: ({ type, ...res }) => {
      console.log(type, res)
      if (type === '历史战役') {
        return 'red'
      }
      return 'blue'
    },
    point: {
      shapeField(v, ...res) {
        if (v.type === '本模型' && v.time > 20) return 'circle'
        // console.log(res, this)
        return 'square'
      }
      // shapeField: 'square',
      // sizeField: () => 2
    },
    style: {
      lineWidth: 1
    },
    xField: 'time',
    yField: 'value',
    seriesField: 'type',
    // colorField: 'type',
    yAxis: {
      label: {
        formatter: (v) => `${(v / 1000).toFixed(2)} k`
      }
    },
    legend: {
      position: 'top'
    },
    smooth: true,
    animate: { enter: { type: 'growInX' } }
  }
  return <Line {...config} />
}
export default ChatLine
