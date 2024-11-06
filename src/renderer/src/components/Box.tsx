import { theme } from 'antd'
import { FC } from 'react'

export const Box: FC<{ children?: React.ReactNode; className?: string }> = (props) => {
  const { token } = theme.useToken()
  return (
    <div
      className={props.className || 'p-10 overflow-auto'}
      style={{
        color: token.colorTextTertiary,
        backgroundColor: token.colorFillAlter,
        borderRadius: token.borderRadius,
        border: `1px dashed ${token.colorBorder}`
      }}
    >
      {props?.children}
    </div>
  )
}
