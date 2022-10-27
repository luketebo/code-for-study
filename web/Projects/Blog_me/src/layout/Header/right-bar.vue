<template>
    <el-menu :default-active="activeIndex"  :ellipsis="false" class="el-menu-demo" mode="horizontal"
        @select="handleSelect">
        <el-menu-item background-color="red" index="1">首页</el-menu-item>
        <el-menu-item index="2">随笔</el-menu-item>
        <el-sub-menu class="subMenu" index="3">
            <template #title>知识</template>
            <el-menu-item index="3-1">编程知识</el-menu-item>
            <el-menu-item index="3-2">生活知识</el-menu-item>
            <el-menu-item index="3-3">奇怪知识</el-menu-item>
        </el-sub-menu>
        <el-sub-menu class="subMenu" index="4">
            <template #title>工具</template>
            <el-menu-item index="4-1">系统工具</el-menu-item>
            <el-menu-item index="4-2">开发工具</el-menu-item>
            <el-menu-item index="4-3">收藏工具</el-menu-item>
        </el-sub-menu>
        <el-sub-menu class="subMenu" index="5">
            <template #title>项目</template>
            <el-menu-item index="5-1">demo</el-menu-item>
            <el-menu-item index="5-2">demo</el-menu-item>
            <el-menu-item index="5-3">demo</el-menu-item>
        </el-sub-menu>
        <el-sub-menu class="subMenu" index="6">
            <template #title>更多</template>
            <el-menu-item index="6-1">demo</el-menu-item>
            <el-menu-item index="6-2">demo</el-menu-item>
            <el-menu-item index="6-3">demo</el-menu-item>
        </el-sub-menu>
        <el-menu-item index="7">谈心</el-menu-item>
        <el-menu-item index="8">技能点</el-menu-item>
        <el-menu-item index="9">博客</el-menu-item>
    </el-menu>
</template>

<script setup lang='ts'>
import { ref, reactive } from 'vue'
const activeIndex = ref('1')
const activeIndex2 = ref('2')

const handleSelect = (key: string, keyPath: string[]) => {
    console.log(key, keyPath);
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

// .el-menu-item{
//     color: transparent;
// }

.el-menu-item.is-active {
    // color: transparent;
    background-color: transparent;
}

.el-menu-demo > li {
    height: 3vw;
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