package sorting

type BubbleSort struct {
}

func (b BubbleSort) Sort(arr []int, sortType SortType) []int {
	length := len(arr)

	for i := 0; i < length; i++ {
		for j := 0; j < length-i-1; j++ {
			if Compare(arr[j], arr[j+1], sortType) {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}

	return arr
}
