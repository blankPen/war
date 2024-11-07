import { app, ipcMain } from 'electron'
import { Worker } from 'worker_threads'
import path from 'path'

// 创建 Worker 实例的工具函数
function createWorker(type: string, params: any) {
  return new Promise((resolve, reject) => {
    const worker = new Worker(path.join(app.getAppPath(), 'resources/worker/algorithm-worker.js'))

    worker.on('message', (result) => {
      if (result.success) {
        resolve(result.result)
      } else {
        reject(new Error(result.error))
      }
      worker.terminate()
    })

    worker.on('error', reject)
    worker.on('exit', (code) => {
      if (code !== 0) {
        reject(new Error(`Worker stopped with exit code ${code}`))
      }
    })

    worker.postMessage({ type, params })
  })
}

// 封装测速逻辑的工具函数
async function withTiming<T>(fn: () => Promise<T>): Promise<T> {
  const start = Date.now()
  const result = await fn()
  const end = Date.now()
  console.log(`计算时间: ${end - start}ms`)
  return result
}

ipcMain.handle('calculator', async (_, params) => {
  return withTiming(() => createWorker('calculator', params))
})

ipcMain.handle('probabilityPIMC', async (_, params) => {
  console.log(params)
  return withTiming(() => createWorker('probabilityPIMC', params))
})
