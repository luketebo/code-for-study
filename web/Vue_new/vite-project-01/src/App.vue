<template>
    <renderDom @on-click="getNum"></renderDom>
</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'
import renderDom from './App'

const getNum = (num:number) => {
    console.log(num)
}

</script>
<style scoped lang='less'>

</style>