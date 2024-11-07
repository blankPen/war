// import { parentPort } from 'worker_threads'
const { parentPort } = require('worker_threads')
const sdk = require('../addon.node')

parentPort?.on('message', (data) => {
  try {
    let result
    if (data.type === 'calculator') {
      const { inital_troops, time_known, compare_data } = data.params
      result = sdk.calculator(compare_data, inital_troops, time_known)
    } else if (data.type === 'probabilityPIMC') {
      const { kr, kb, data: pimcData, t_known } = data.params
      result = sdk.probabilityPIMC(kr, kb, pimcData, t_known)
    }

    parentPort?.postMessage({ success: true, result })
  } catch (error) {
    parentPort?.postMessage({ success: false, error: error.message })
  }
})
