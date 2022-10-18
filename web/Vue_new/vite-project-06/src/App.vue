<template>

    <div>
        <p>action-use: {{Test.user}}</p>
        <hr/>
        <p>action-name: {{Test.name}}</p>
        <hr/>
        <p>getters: {{Test.newName}}</p>
        <hr/>
        <button @click="change">change</button>
    </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'
import {useTestStore} from "./store"

const Test = useTestStore()

const change = () => {
    Test.setUser()
}

</script>
<style scoped lang='less'>

</style>