<template>

    <div class="content">
        <el-backtop :right="100" :bottom="100" />
        <div class="content-f">
            <homePage1></homePage1>
            <homePage2></homePage2>
        </div>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import homePage1 from '../../components/content/homepage_01.vue'
import homePage2 from '../../components/content/homepage_02.vue'

</script>
<style scoped lang='less'>
@border: #ccc;

.content {
    height: auto;
    width: 80%;
    border: 1px solid @border;
    margin: 0 auto;
    display: flex;
    justify-content: center;
    align-items: center;
    &-f{
        width: inherit;
    }
}
</style>