<template>

 <div> i am a A</div>
 <div>Luke</div>
 <div ref="data">{{ data_ }}</div>
 <button @click="change">edit</button>
 <hr />

</template>

<script setup lang='ts'>
import { ref, onBeforeMount, onMounted, onBeforeUpdate, onUpdated, onBeforeUnmount, onUnmounted, onRenderTracked, onRenderTriggered} from 'vue'

const data = ref<HTMLDivElement>()
const data_ = ref<string>('Luke')

const change = () => {
    data_.value = "Tebo"
}

// beforeCreate created setup 语法糖模式是没有这两个生命周期的 setup去代替
console.log("setup")
console.log(data_.value)
// 挂载  
// onBeforeMount 读不到dom onMounted 可以去读dom
onBeforeMount(() => {
    console.log("BeforeMount", data.value)
})
onMounted(() => {
    console.log("Mounted", data.value)
})
// 更新
/// onBeforeUpdate 获取更新之前的dom onUpdated 获取更新之后的dom
onBeforeUpdate(() => { 
    // 针对dom元素吗？
    console.log("BeforeUpdate", data.value?.innerText);
})
onUpdated(() => {
    console.log("Updated", data.value?.innerText);
    
})
// 卸载
onBeforeUnmount(() => {
    console.log("BeforeUnmount", data.value);
})
onUnmounted(() => {
    console.log("Unmounted", data.value)
})
// 调试作用
onRenderTracked((e) => {

})
onRenderTriggered((e) => {

})
</script>
<style scoped>

</style>