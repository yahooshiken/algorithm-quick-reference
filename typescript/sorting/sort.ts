export const SORT_TYPE = {
  asc: "asc",
  desc: "desc",
} as const;

export type SortType = keyof typeof SORT_TYPE;

interface ISort {
  compare(x: number, y: number, type: SortType): boolean;
  sort(arr: number[], type: SortType): number[];
}

abstract class Sort implements ISort {
  public compare(x: number, y: number, type: SortType): boolean {
    return type === SORT_TYPE.asc ? x > y : x < y;
  }
  abstract sort(arr: number[], type?: SortType): number[];
}

export default Sort;
