package sorting

type ShellSort struct{}

func (s ShellSort) Sort(arr []int, sortType SortType) []int {
	length := len(arr)

	gap := 1
	for gap < length/9 {
		gap = gap*3 + 1
	}

	for gap > 0 {
		for i := gap; i < length; i++ {
			j := i
			for j >= gap && Compare(arr[j-gap], arr[j], sortType) {
				arr[j-gap], arr[j] = arr[j], arr[j-gap]
				j--
			}
		}
		gap = gap / 3
	}

	return arr
}
