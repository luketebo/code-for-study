<template>
    <el-scrollbar max-height="100vh">
        <Header></Header>
        <Content></Content>
    </el-scrollbar>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import Content from './Content/index.vue'
import Header from './Header/index.vue'


</script>
<style scoped lang='less'>

</style>