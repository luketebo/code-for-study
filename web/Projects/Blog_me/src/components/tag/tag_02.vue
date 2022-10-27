<template>

    <div class="tag2">
        <header class="tag2-header">文章分类</header>
        <main class="tag2-main">
            <el-menu default-active="2" class="el-menu-vertical-demo" @open="handleOpen" @close="handleClose">
                <el-menu-item index="1">
                    <span>Python</span>
                </el-menu-item>
                <el-menu-item index="2">
                    <span>Java</span>
                </el-menu-item>
                <el-menu-item index="3">
                    <span>算法</span>
                </el-menu-item>
                <el-menu-item index="4">
                    <span>Linux</span>
                </el-menu-item>
            </el-menu>
        </main>
    </div>

</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
const handleOpen = (key: string, keyPath: string[]) => {
    console.log(key, keyPath)
}
const handleClose = (key: string, keyPath: string[]) => {
    console.log(key, keyPath)
}

</script>
<style scoped lang='less'>
@border: #ccc;

.tag2 {
    height: auto;
    width: 80%;
    border-radius: 3px;
    border: 1px solid @border;
    margin: 15px 0;
    &-header {
        display: flex;
        justify-content: flex-start;
        padding: 8% 0 8% 20px;
    }
    &-main {
        ul > li {
            height: 30px;
            padding: 0;
            margin: 0;
        }
        ul li > span {
            padding: 0;
            margin: 0;
        }
        :deep(.el-menu-item span) {
            padding: 0;
            margin: 0;
        }

    }
}
</style>