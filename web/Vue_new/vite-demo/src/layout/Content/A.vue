<template>
    <div>A</div>
    <button @click="emit">emit</button>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import { getCurrentInstance } from 'vue'

const instance = getCurrentInstance()
const emit = () => {
    // emit 发送消息
    instance?.proxy?.$Bus.emit("on-click", 'mitt')
    instance?.proxy?.$Bus.emit("on-click2", 'mitt2')
}

</script>
<style scoped lang='less'>

</style>