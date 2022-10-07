<template>
    <input id="ipt" v-model="message" type="text" />
    <br />
    <input v-model="message_" type="text" />


</template>

<script setup lang='ts'>
import { reactive, ref, watch, watchEffect } from "vue"

let message = ref<string>("Luke")

let message_ = ref<string>("Tebo")

const stop = watchEffect((oninvalidate) => {

    // 非惰性 自动调用
    // console.log("message: ", message.value)
    oninvalidate(() => {
        // 在监听之前，执行 可以做一些操作，如防抖，清除接口之类的
        console.log("before");
    })
}, {
    // flush: "post"
    onTrigger (e) {
        debugger
    }
})

const stopWatch = () => stop()
</script>
<style scoped>

</style>