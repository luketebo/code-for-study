<template>
    <div class="layout">
        <Menu></Menu>
        <div class="layout-right">
            <Header></Header>
            <Content></Content>
        </div>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import Menu from './Menu/index.vue'
import Header from './Header/index.vue'
import Content from './Content/index.vue'


</script>
<style scoped lang='less'>
.layout {
    display: flex;
    height: 100%;
    overflow: hidden;

    &-right {
        flex: 1;
        display: flex;
        flex-direction: column;
    }
}
</style>