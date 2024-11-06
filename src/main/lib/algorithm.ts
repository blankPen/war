import { ipcMain } from 'electron'
import sdk from './algorithm-sdk'

ipcMain.handle('calculator', async (_, params) => {
  const { inital_troops, time_known, compare_data } = params
  console.log('==>params', params)
  const result = sdk.MyFunction(compare_data, inital_troops, time_known)
  console.log('==>result', result)
  return result
})
