<template>

    <div class="content">
        <el-backtop :right="100" :bottom="100" />
        <div class="content-f">
            <homepage_01Vue></homepage_01Vue>
            <homepage_02Vue></homepage_02Vue>
        </div>
    </div>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import homepage_01Vue from './homepage_01.vue';
import homepage_02Vue from './homepage_02.vue';

</script>
<style scoped lang='less'>
.content {
    width: 80%;
    height: inherit;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;

    &-f {
        width: inherit;
        justify-content: center;
        align-items: center;
    }
}
</style>