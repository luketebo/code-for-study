import { createApp } from 'vue'
import './style.css'
import App from './App.vue'
import {createPinia} from 'pinia'

const app = createApp(App)
const store = createPinia()

app.use(store)

app.mount('#app')
