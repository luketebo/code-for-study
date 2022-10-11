import { createApp } from 'vue'
import ElementPlus from 'element-plus'
import 'element-plus/dist/index.css'
import './style.css'
import mitt from 'mitt'
import App from './App.vue'
import Card from './components/Card/index.vue'
// createApp(App).component("Card", Card).use(ElementPlus).mount('#app')


const Mit = mitt()

const app = createApp(App)

declare module 'vue' {
    export interface ComponentCustomProperties{
        $Bus: typeof Mit
    }
}

app.config.globalProperties.$Bus = Mit

app.mount('#app')