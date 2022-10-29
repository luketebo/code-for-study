<template>

    <div class="paper">
        <div class="paper-left">目录</div>
        <div class="paper-center">内容</div>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive, } from 'vue'


</script>
<style scoped lang='less'>
@border: #ccc;

.paper {
    height: 100vw;
    width: 100%;
    // background-color: red;
    // padding: 0 13.9%;
    margin-right: 100%;
    border: 1px solid @border;
    display: flex;
    flex-direction: row;

    &-left {
        height: inherit;
        width: 14%;
        border: 1px solid @border;
    }

    &-center {
        height: inherit;
        width: 86%;
        border: 1px solid @border;

    }
}
</style>