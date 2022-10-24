export interface ChinaTotal {
  nowLocalWzz: number;
  deadAdd: number;
  mtime: string;
  highRiskAreaNum: number;
  heal: number;
  dead: number;
  noInfect: number;
  localWzzAdd: number;
  localConfirmAdd: number;
  nowConfirm: number;
  mRiskTime: string;
  showLocalConfirm: number;
  confirm: number;
  suspect: number;
  nowSevere: number;
  importedCase: number;
  confirmAdd: number;
  mediumRiskAreaNum: number;
  localConfirm: number;
  showlocalinfeciton: number;
  noInfectH5: number;
  localConfirmH5: number;
  local_acc_confirm: number;
}

export interface ChinaAdd {
  noInfectH5: number;
  confirm: number;
  heal: number;
  dead: number;
  nowSevere: number;
  importedCase: number;
  nowConfirm: number;
  suspect: number;
  noInfect: number;
  localConfirm: number;
  localConfirmH5: number;
}

export interface ShowAddSwitch {
  all: boolean;
  confirm: boolean;
  suspect: boolean;
  dead: boolean;
  heal: boolean;
  noInfect: boolean;
  nowConfirm: boolean;
  nowSevere: boolean;
  importedCase: boolean;
  localConfirm: boolean;
  localinfeciton: boolean;
}

export interface Today {
  confirm: number;
  isUpdated: boolean;
}

export interface Total {
  highRiskAreaNum: number;
  continueDayZeroLocalConfirmAdd: number;
  nowConfirm: number;
  showHeal: boolean;
  provinceLocalConfirm: number;
  mediumRiskAreaNum: number;
  mtime: string;
  showRate: boolean;
  wzz: number;
  continueDayZeroLocalConfirm: number;
  confirm: number;
  dead: number;
  heal: number;
  adcode: string;
}

export interface Today2 {
  local_confirm_add: number;
  abroad_confirm_add: number;
  dead_add: number;
  confirm: number;
  confirmCuts: number;
  isUpdated: boolean;
  tip: string;
  wzz_add: number;
}

export interface Total2 {
  continueDayZeroConfirmAdd: number;
  adcode: string;
  confirm: number;
  dead: number;
  showRate: boolean;
  mtime: string;
  showHeal: boolean;
  wzz: number;
  mediumRiskAreaNum: number;
  highRiskAreaNum: number;
  nowConfirm: number;
  heal: number;
  provinceLocalConfirm: number;
  continueDayZeroConfirm: number;
  continueDayZeroLocalConfirmAdd: number;
}

export interface Today3 {
  confirm: number;
  confirmCuts: number;
  isUpdated: boolean;
  wzz_add: string;
  local_confirm_add: number;
}

export interface Total3 {
  highRiskAreaNum: number;
  continueDayZeroLocalConfirmAdd: number;
  showHeal: boolean;
  wzz: number;
  adcode: string;
  showRate: boolean;
  heal: number;
  provinceLocalConfirm: number;
  mediumRiskAreaNum: number;
  mtime: string;
  confirm: number;
  dead: number;
  nowConfirm: number;
  continueDayZeroLocalConfirm: number;
  grade: string;
}

export interface Child2 {
  date: string;
  today: Today3;
  total: Total3;
  name: string;
  adcode: string;
}

export interface Child {
  name: string;
  adcode: string;
  date: string;
  today: Today2;
  total: Total2;
  children: Child2[];
}

export interface AreaTree {
  today: Today;
  total: Total;
  children: Child[];
  name: string;
}

export interface Diseaseh5Shelf {
  lastUpdateTime: string;
  chinaTotal: ChinaTotal;
  chinaAdd: ChinaAdd;
  isShowAdd: boolean;
  showAddSwitch: ShowAddSwitch;
  areaTree: AreaTree[];
}

export interface LocalCityNCOVDataList {
  date: string;
  isUpdated: boolean;
  mtime: string;
  isSpecialCity: boolean;
  city: string;
  adcode: string;
  local_confirm_add: number;
  local_wzz_add: string;
  mediumRiskAreaNum: number;
  highRiskAreaNum: number;
  province: string;
}

export interface RootObject {
  diseaseh5Shelf: Diseaseh5Shelf;
  localCityNCOVDataList: LocalCityNCOVDataList[];
}
