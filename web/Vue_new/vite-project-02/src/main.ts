import { createApp } from "vue";
import "./style.css";
import App from "./App.vue";
import Loading from './components/Loading'

let app = createApp(App)

// 插件注册都是用use
app.use(Loading)

app.mount("#app");

type Lod = {
    show: () => void,
    hide: () => void
}

// 类型声明
declare module '@vue/runtime-core' {
    export interface ComponentCustomProperties {
            $loading: Lod
    }
}