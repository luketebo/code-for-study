import { createApp } from 'vue'
import './style.css'
import App from './App.vue'
import {createPinia, PiniaPlugin} from 'pinia'

const piniaPlugin = (context: PiniaPlugin) => {
    console.log(context, )
}




const app = createApp(App)
const store = createPinia()





app.use(store)

app.mount('#app')
