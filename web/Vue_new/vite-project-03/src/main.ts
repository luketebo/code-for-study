import { createApp } from 'vue'
import './style.css'
import ELementPlus from 'element-plus'
import "element-plus/dist/index.css"
import App from './App.vue'
import './index.css'


const app = createApp(App)

app.use(ELementPlus)


app.mount('#app')
