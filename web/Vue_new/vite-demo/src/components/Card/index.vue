<template>

 <div class="card">
    <div class="card-header">
        <div>主标题</div>
        <div>副标题</div>
    </div>
    <div class="card-content" v-if="content">
        {{ content }}
    </div>
 </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'

type Props = {
    content?: string
}

// 接受父组件传值
defineProps<Props>()

</script>
<style scoped lang='less'>
@border: #ccc;
.card{
    border: 1px solid @border;
    &:hover{
        box-shadow: 0 0 10px @border;
    }
    &-header{
        display: flex;
        justify-content: space-between;
        padding: 10px;
        border-bottom: 1px solid @border;
    }
    &-content{
        padding: 10px;
    }
}
</style>