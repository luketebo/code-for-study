<template>

    <div>
        <div v-for="item in list">
            {{item}}
        </div>
    </div>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import { axios } from './server'

const list = await axios('./data.json')

console.log(list)

</script>
<style scoped lang='less'>

</style>