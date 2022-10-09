import { createApp } from 'vue'
import ElementPlus from 'element-plus'
import 'element-plus/dist/index.css'
import './style.css'
import App from './App.vue'
import Card from './components/Card/index.vue'
createApp(App).component("Card", Card).use(ElementPlus).mount('#app')
