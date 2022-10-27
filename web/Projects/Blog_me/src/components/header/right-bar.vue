<template>
    <el-menu :default-active="activeIndex"   :ellipsis="false" class="el-menu-demo" mode="horizontal"
        @select="handleSelect">
        <el-menu-item @click="toPage('/')" background-color="red" index="1">首页</el-menu-item>
        <el-menu-item @click="toPage('essay')" index="2">随笔</el-menu-item>
        <el-sub-menu class="subMenu" index="3">
            <template #title>知识</template>
            <el-menu-item @click="toPage('code')" index="3-1">编程知识</el-menu-item>
            <el-menu-item @click="toPage('life')" index="3-2">生活知识</el-menu-item>
            <el-menu-item @click="toPage('odd')" index="3-3">奇怪知识</el-menu-item>
        </el-sub-menu>
        <el-sub-menu class="subMenu" index="4">
            <template #title>工具</template>
            <el-menu-item @click="toPage('system')" index="4-1">系统工具</el-menu-item>
            <el-menu-item @click="toPage('operate')" index="4-2">开发工具</el-menu-item>
            <el-menu-item @click="toPage('start')" index="4-3">收藏工具</el-menu-item>
        </el-sub-menu>
        <el-sub-menu class="subMenu" index="5">
            <template #title>项目</template>
            <el-menu-item @click="toPage('demo')" index="5-1">demo</el-menu-item>
            <el-menu-item @click="toPage('demo')" index="5-2">demo</el-menu-item>
            <el-menu-item @click="toPage('demo')" index="5-3">demo</el-menu-item>
        </el-sub-menu>
        <el-sub-menu class="subMenu" index="6">
            <template #title>更多</template>
            <el-menu-item @click="toPage('demo')" index="6-1">demo</el-menu-item>
            <el-menu-item @click="toPage('demo')" index="6-2">demo</el-menu-item>
            <el-menu-item @click="toPage('demo')" index="6-3">demo</el-menu-item>
        </el-sub-menu>
        <el-menu-item @click="toPage('follow')" index="7">谈心</el-menu-item>
        <el-menu-item @click="toPage('skill')" index="8">技能点</el-menu-item>
        <el-menu-item @click="toPage('blog')" index="9">博客</el-menu-item>
    </el-menu>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
import { useRouter } from "vue-router"

const activeIndex = ref('1')
const activeIndex2 = ref('2')

const handleSelect = (key: string, keyPath: string[]) => {
    console.log(key, keyPath);
}

const router = useRouter()

const toPage = (name: string) => {
    console.log(name);
    
    router.push(name)
}


</script>
<style scoped lang='less'>
.el-menu-demo {
    height: inherit;
    border-bottom: none;
    border-right: none;
    justify-content: space-around;
    align-items: center;
}

.el-menu--popup-container {
    border-right: none;
    background-color: red;
}

// .el-menu-item{
//     color: transparent;
// }

.el-menu-item.is-active {
    // color: transparent;
    background-color: transparent;
}

.el-menu-demo > li {
    height: 2vw;
}

.el-menu--horizontal > .el-menu-item {
    width: 5%;

}

.el-menu--horizontal > .el-sub-menu {
    border-bottom: none;
}

.subMenu{
    :deep(.el-sub-menu__title){
        padding: 0;
        
    }
}

</style>