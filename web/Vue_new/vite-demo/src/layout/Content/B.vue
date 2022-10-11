<template>
    <div>B</div>

</template>
<script setup lang='ts'>
import { ref, reactive } from 'vue'
import { getCurrentInstance } from 'vue'

const Bus = (str:any) => {
    console.log(str, "===========> B")
}

const instance = getCurrentInstance()

// on 接受消息
// instance?.proxy?.$Bus.on('on-click', (str) => {
//     console.log(str, '==========> B')
// })
// * 可以监听所有
instance?.proxy?.$Bus.on('*', (str) => {
    console.log(str, '==========> B')
})

instance?.proxy?.$Bus.off('on-click', Bus)

instance?.proxy?.$Bus.all.clear()
</script>
<style scoped lang='less'>

</style>