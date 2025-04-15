# Define the data
nm <- c('Session 1', 'Session 2', 'Session 3')
val <- c(24, 24, 22)

# Get the x-coordinates of the bars
bar_centers <- barplot(val, names.arg = nm, plot = FALSE)

# Create the bar plot
barplot(val, names.arg = nm, ylim = c(0, 30), col = 'pink', ylab = 'Number of Participants', main = 'Participants for each Session', yaxt = "n")

# Manually add y-axis labels with increments of 2
axis(2, at = seq(0, 30, by = 2), las = 1)

# Add labels on top of each bar, centered
text(x = bar_centers, y = val + 1, labels = val)
