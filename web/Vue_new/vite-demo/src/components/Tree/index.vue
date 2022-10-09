<template>

 <div :key="index" v-for="(item, index) in data" style="margin-left:10px">
    {{ item.name }}
    <!-- 递归第一种 -->
    <TreeItem v-if="item?.children?.length" :data="item.children"></TreeItem>

 </div>

</template>

<script setup lang='ts'>
import {ref, reactive} from 'vue'
import TreeItem from './index.vue'

type TreeList = {
    name: string,
    icon?: string,
    children?: TreeList[] | []
}

type Props = {
    data?: TreeList[]
}

defineProps<Props>()

</script>
<!-- 第二种 -->
<script lang="ts">
export default {
    name: "TreeItem"
}
</script>

<style scoped lang='less'>

</style>