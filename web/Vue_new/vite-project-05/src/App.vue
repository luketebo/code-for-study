<template>

    <div :class="index == current ? 'active' : ''" v-for="(item, index) in 10" :key="item" @click="change(index)">
        {{item}}
    </div>

</template>

<script setup lang='ts'>
import {ref, reactive, onMounted} from 'vue'

let current = ref(2)

const change = (index: number) => {
    current.value = index
    console.log("current: " + current + " index: " + index)
}

// const onMounted = () => {
//     change()
// }

</script>
<style scoped lang='less'>
.active {
    background-color: pink;
}
div {
    height: 30px;
    width: 30px;
    margin: 25px;
    border: 1px solid red;
}
</style>