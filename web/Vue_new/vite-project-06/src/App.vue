<template>

    <div>
        origin value {{ Test.current}}
    </div>
    <div>
        pinia: {{current}} --- {{name}}
        change:
        <button @click="change">change</button>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import { useTestStore } from './store'
import { storeToRefs } from 'pinia'
const Test = useTestStore()
// pinia 解构不具有响应式
const {current, name} = storeToRefs(Test)

const change = () => {
    Test.current ++
    console.log(current, name);
}

</script>
<style scoped lang='less'>

</style>