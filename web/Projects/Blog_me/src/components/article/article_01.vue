<template>

    <div class="article">
        <div class="article-title">题目</div>
        <div class="article-info">个人信息</div>
        <el-divider></el-divider>
        <div class="article-content">文章内容</div>
        <a class="article-turn">阅读全文</a>
    </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'


</script>
<style scoped lang='less'>
@border: #ccc;
.article {
    height: 12vw;
    width: 85%;
    display: flex;
    margin-top: 15px;
    margin-bottom: 5px;
    flex-direction: column;
    justify-content: start;
    border-radius: 3px;
    border: 1px solid @border;

    &-title {
        height: 3vw;
        font-size: 20px;
        font-weight: bold;
    }

    &-info {
        height: 2vw;
    }

    &-content {
        height: 6vw;
    }

    &-turn {
        height: 1.5vw;
        display: flex;
        justify-content: flex-end;
    }
}

.el-divider {
    margin: 5px 0;
}

</style>