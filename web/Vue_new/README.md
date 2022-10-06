# Vue 笔记

> 学习进度： 第四节 2022/10/05
>
> ​				  第七节 2022/10/06

## Vue 初识

### 基础配置

+ 安装nodejs
+ 安装nvm

对于基础配置的安装，通过手动安装比较麻烦，如果是windows用户，更加推荐使用包管理工具下载，不用配置环境

### 构建项目

+ 简易项目构建

```bash
npm init vite@latest # 项目构建

cd "项目目录"
npm install && npm i # 下载依赖

npm run dev # 启动项目
```

+ 完整项目构建

```bash
npm init vue@latest # 项目构建

cd "项目目录"
npm install && npm i # 下载依赖

npm run dev # 启动项目
```

###  代码学习

#### 模板语法 & vue 指令

##### 模板插值语法

> error: 使用el表达式的时候无法获取数据

在script 声明一个变量可以直接在template 使用用法 {{ 变量名称 }}

```vue
<template>
	<div>
        {{ message }}
    </div>
</template>

<script setup lang="ts">
const message = "Luke Tebo"
</script>

<style>

</style>
```

模板语法的妙用

```vue
<template>
	<div>
        {{ message == 0 ? "Luke" : "Tebo" }}  // 条件运算
        {{ message + 1 }} // 算数运算
        {{ arr.split(',') }}   // 函数调用
    </div>	
</template>

<script setup lang="ts">
    const message:number = 1
    const arr:string = "Luke, Tebo"
</script>

<style>
</style>
```



##### 指令

v- 开头都是vue 指令

v-text 用来显示文本

v-html 用来显示富文本

```vue
<template>
	<div v-text="message"></div>
	<div v-show="code"></div>
</template>

<script setup lang="ts">
    const message:string = "message"
    const code:string = "<h1>code</h1>"
</script>

<style>
</style>
```



v-if 用来控制元素的显示隐藏

v-show 用于控制元素得到显示隐藏

```vue
<template>
	<div v-if="flag"> // v-if 更加消耗性能
        v-if
    </div>
	<div v-show="flag">
        v-show
    </div>
</template>

<script setup lang="ts">
const flag:boolean = true
    
</script>

<style>

</style>
```



v-on 简写@ 用来给元素添加事件

```vue
<template>
	<div>
        <button @click="clickTap">
            123
    </button>
    </div>
</template>

<script setup lang="ts">
const clickTap = () => {
    console.log("click")
}
</script>
<style></style>
```

阻止冒泡事件

```vue
<template>
	<div @click="parent">
        <button @click="clickTap"> 123 </button>
        // 仔细比较 两个按钮在控制台的输出 类似操作较多可自行实践
        <button @click.stop = "clickTap"> 321 </button>
    </div>
</template>

<script setup lang="ts">
const clickTap = () => {
    console.log("click");
}
const parent = () => {
    console.log("parent");
}
</script>
```

阻止表单提交

```vue
<template>
	<form action="/">
		// 不刷新
		<button @click.prevent="submit" type="submit"> submit </button>
		// 刷新
		<button @click="submit" type="submit"> submit_ </button>
	<form>
</template>

<script setup lang="ts">
const submit = () => {
	console.log("child")
}
</script>

<style></style>
```



v-bind 简写: 用来绑定元素的属性attr

案例1

```vue
<template>
	<div :class="[flag ? "a" : "b"]> luke tebo  </div>
</template>

<script setup lang="ts">
const flag: boolean = false
</script>

<style>
.a {
color: red;
}

.b {
color: blue;
}
</style>
```

案例2

```vue
<template>
  <div :class="flag">{{ flag }}</div>
</template>
 
<script setup lang="ts">
type Cls = {
  other: boolean,
  h: boolean
}
const flag: Cls = {
  other: false,
  h: true
};
</script>
 
<style>
.active {
  color: red;
}
.other {
  color: blue;
}
.h {
  height: 300px;
  border: 1px solid #ccc;
}
</style>
```

v-bind 绑定style

```vue
<template>
  <div :style="style">2222</div>
</template>
 
<script setup lang="ts"> 
type Style = {
  height: string,
  color: string
}
const style: Style = {
  height: "300px",
  color: "blue"
}
</script>
 
<style>
</style>
```



v-for

```vue
<template>
	<div :key="item" v-for = "item in Arr">{{ item }}</div>
</template>

<script setup lang="ts">
const arr:Array<number> = [1, 2, 3, 4, 5]
</script>

<style></style>
```



v-model

> ref ? 是啥

```vue
<template>
  <input v-model="message" type="text" />
  <div>{{ message }}</div>
</template>
 
<script setup lang="ts">
import { ref } from 'vue'
const message = ref("v-model")
</script>
 
<style>
.active {
  color: red;
}
.other {
  color: blue;
}
.h {
  height: 300px;
  border: 1px solid #ccc;
}
</style>
```



#### 虚拟Dom 和 diff算法

> 没搞明白

#### ref 全家桶

> ref isRef shallowRef triggerRef  customRef 
>
> 目的是将元素变成响应式

*tips: vscode 配置 vue 模板输出*

> 打开vscode 右键设置 -> 配置用户配置用户代码片段
> 搜索 vue 
>
> ```json
> {
>      "Print to console": {
>     "prefix": "vue3",
>     "body": [
>       "<template>",
>       "",
>       " <div></div>",
>       "",
>       "</template>",
>       "",
>       "<script setup lang='ts'>",
>       "import {ref, reactive} from 'vue'",
>       "",
>       "</script>",
> 
>       "<style scoped>",
>       "",
>       "</style>"
>     ],
>     "description": "Log output to console"
>   }
> }
> ```
>
> 然后在代码界面 敲vue3 就可以出现模板


ref 使用

```vue
<template>
	<div>
        {{ Man }}
        <button @click="change">change</button>
    </div>
</template>
<script setup lang="ts">
import {ref} from 'vue'
// 第一种方式 自己做类型推导
const Man = ref({name: "Luke"})
const change = () => {
	man.value.name = "Tebo"
    console.log(man)
}
// 第二种方式 适用于类型较简单
type M = {
    name: string
}
const Man = ref<M>({name: "Luke"})
// 第三种方式 类型比较复杂的时候，可以使用
import type {Ref} from 'vue'
const Man:Ref<M> = ref({name: "Luke"})
</script>
<style scoped>

</style>
```

isRef 使用

```vue
<template>
	<div>
        {{ Man }}
    </div>
<button @click="change">change</button>

</template>
<script setup lang="ts">
    import {ref, isRef} from 'vue'
    const Man = ref({name: "Luke"})
    
    const change = () =》 {
        // 判断是否是Ref 对象
		console.log(isRef(Man))
    }
</script>
<style scoped>

</style>
```

shallowRef 使用

```vue
<template>
	<div>
        {{ Man }}
    </div>
<button @click="change">change</button>
</template>
<script setup lang="ts">
 import {ref, shallowRef} from 'vue'

 // 切记 ref 和 shallowRef 不能够混用  具体看下一个混用代码
const Man = shallowRef({name: "Luke"})

const change = () => {
    Man.value.name = "Tebo"
    // 这时会发现 当点击按钮的时候 页面并没有改变，但是console中的值却改变了，这就是ref和shallowRef的区别
    // 在triggerRef 当中会有简单介绍
    console.log(Man)
}
</script>
<style scoped>

</style>
```

混用

```vue
<template>
	<div>
        {{ Man }}
    </div>
<button @click="change">change</button>
</template>
<script setup lang="ts">
 import {ref, shallowRef} from 'vue'

const Man_ = ref({name: "ref"})
const Man = shallowRef({name: "shallowRef"})

const change = () => {
    Man_.value.name = "Tebo"
    Man.value.name = "Tebo"
	// 当两个混用的时候，你点击按钮，会发现原本不变的shallowRef也会变成Tebo， 所以这两个不能混用
    console.log(Man)
}
</script>
<style scoped>

</style>
```

triggerRef 使用

```vue
<template>
	<div>
        {{ Man }}
    </div>
<button @click="change">change</button>
</template>
<script setup lang="ts">
 import {ref, shallowRef} from 'vue'

const Man = shallowRef({name: "shallowRef"})


const change = () => {
    
    Man.value.name = "Tebo"
    triggerRef(Man) // 当调用这函数的时候，会发现也页面也会跟着改变
 	/*
 	这是因为在vue源码的底层实现的，当调用ref的时候也会调用该函数，所以，ref和shallowRef混用就会导致
 	shallowRef 页面也被刷新
 	*/
    console.log(Man)
}
</script>
<style scoped>

</style>
```

customRef使用

```vue
<template>
	<div>
        {{ obj }}
    </div>
<button @click="change">change</button>
</template>
<script setup lang="ts">
import {customRef} from 'vue'
   
// 看不懂     大概就是自己定义一个ref对象吧
function MyRef<T>(value: T) {
    let timer: any
    return customRef((track, trigger) => {
        return {
            get() {
                return value
            },
            set(newVal) {
                clearTimeout(timer)
                timer = setTimeout(() => {
                    console.log("what")
                    value = newVal
                    timer = null
                    trigger()
                }, 500)
            }
        }
    })
}
    
const obj = MyRef<string> ('customRef : Luke')

const change = () => {
    obj.value = 'customRef: Tebo'
    
}
</script>
<style scoped>

</style>
```

ref的妙用 ----->  通过ref获取网页元素对象

```vue
<template>
<div ref="dom">
    i am dom
    </div>
<button @click='find'>find</button>
</template>
<script setup lang="ts">
import {ref} from 'vue'

const dom = ref<HTMLElement>()

const find = () => {
    console.log(dom.value?.innerText) // 获取界面元素
}

</script>
<style scoped>

</style>
```

#### reactive 全家桶

>将元素变成响应式

与ref的区别

| 功能       | ref          | reactive                             |
| ---------- | ------------ | ------------------------------------ |
| 支持类型   | 支持所有类型 | 支持引用类型 Array, Object, Map, Set |
| 取值，赋值 | 需要.value   | 不需要.value                         |

reactive 绑定表单元素

```vue
<template>
<div>
    <form>
   		<input v-model="form.name" />
    	<br />
    	<input v-model="form.age" />
   	 	<br />
    	<button @click="submit">submit</button>      
    </form>
    </div>
</template>
<script setup lang="ts">
import { reactive } from 'vue'

let form = reactive {
    name: "Luke",
    age: 18
}    
const submit = () => {
    console.log(form);
}

</script>
<style scoped>

</style>
```

reactive 绑定数组

```vue
<template>

<div>
    <ul>
        <li v-for="item in list">
    			 {{ item }}
    	</li>
    </ul>
    <button @click="add">add </button>
</div>
</template>
<script setup lang="ts">
import { reactive } from 'vue'
    
let list = reactive<string[]>([])

const add = () => {
    list.push("Luke")
}


</script>
<style scoped>

</style>
```

reactive 绑定数组 （异步）

```vue
<template>

<div>
    <ul>
        <li v-for="item in list">
    			 {{ item }}
    	</li>
    </ul>
    <button @click="add">add </button>
    <ul>
        <li v-for="item in list_">
    			 {{ item }}
    	</li>
    </ul>
    <button @click="add_">add </button>
</div>
</template>
<script setup lang="ts">
import { reactive } from 'vue'
// 第一种方法
 /*
数组 通过push 加 解构的方式解决
*/
let list = reactive<string[]>([])

const add = () => {
    // 异步 模拟
    setTimeout(() => {
        let res = ["Lu", "Ke", "Te", "Bo"]
        // 当直接使用 list = res 时，会出现 页面没有改变数据，但是值发生了变化，这是因为破坏了reactive原先的proxy  
        list.push(...res) // 解构
        console.log(list)
    }, 200)
}

// 第二种方法 
/*
添加一个对象，将数组作为一个属性 
*/

let list_ = reactive<{
    arr: string[]
}>({
    arr: []
})

const add_ = () => {
    setTimeout(() => {
        let res = ["Lu", "Ke", "Te", "Bo"]
        list.arr = res
        console.log(res)
    }, 200)
}

</script>
<style scoped>

</style>
```

readonly 的使用

```vue
<template>
<button @click="show"> show</button>
<button @click="show_"> show_</button>

</template>
<script setup lang="ts">
import { reactive, readonly } from 'vue'

    let obj = reactive({name: "Luke"})
    const read = readonly(obj)
    // read.name = "Tebo" // 不能赋值
    const show = () => {
        read.name = "Tebo"
        console.log(obj, read)
    }
    const show_ = () => {
        obj.name = "Tebo"
        console.log(obj, read)
    }
    /*
    show和show_两个在页面呈现的方式不太一样
    read 不能改变， 但是会受到原来的obj的影响
    */

</script>
<style scoped>

</style>
```

shallowReactive 使用

```vue
<template>

    <div>
       reactive {{ obj_}}
       shallowReactive {{ obj }}
    </div>
    <button @click="edit">edit</button>
    <button @click="edit_">edit_</button>
    <button @click="_edit_">_edit_</button>


</template>

<script setup lang='ts'>
import { ref, reactive, readonly, shallowReactive } from 'vue'
const obj_ = reactive({name: "Luke"})

const obj:any = shallowReactive({
    foo: {
        bar: {
            num: 1
        }
    }
})

const edit = () => {
    /*
    改变shallowReactive的值 和ref差不多
    浅层变化 数值发生了变化，但是界面没有被渲染
    */
    obj.foo.bar.num = 333
    console.log(obj)
}

const edit_ = () => {
    /*
    foo就处于浅层 所有通过这个按钮可以实现 页面改变
    */
    obj.foo = {name: "Luke"}
    console.log(edit_)
}

const _edit_ = () => {
    /*
    和shallowref一样 当reactive发生变化的时候，shallowReactive也会改变
    */
    obj_.name = "Vue"
    obj.foo.bar.num =  "what"
    console.log(obj)
}

</script>
<style scoped>

</style> 
```



