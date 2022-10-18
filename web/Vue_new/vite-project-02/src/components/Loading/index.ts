import type { App, VNode } from "vue";

import Loading from "./index.vue";
import { createVNode, render } from "vue";

export default {
  // 对象形式和函数形式，对象形式一定有install
  install(app: App) {
    const Vnode: VNode = createVNode(Loading);
    // 挂载
    render(Vnode, document.body)
    app.config.globalProperties.$loading = {
        show: Vnode.component?.exposed?.show,
        hide: Vnode.component?.exposed?.hide
    }
    app.config.globalProperties.$loading.show()
    // 读取 妙招 通过抛出
    console.log(app, 123, Vnode.component?.exposed)
  },
};
