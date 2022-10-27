<template>

    <div class="content">
        <div>内容</div>

    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'

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
}
</style>